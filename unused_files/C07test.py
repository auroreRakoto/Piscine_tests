#!/usr/bin/env python3
import sys, subprocess, shutil, glob, os

def die(msg, code=1):
    print(msg); sys.exit(code)

def main():
    if len(sys.argv) < 2 or not sys.argv[1].startswith("C") or len(sys.argv[1])!=3:
        die("Usage: run_c07.py CXX [eval] [TEST_DIR]")
    target = sys.argv[1]
    mode   = sys.argv[2] if len(sys.argv) >= 3 else ""
    testdir= sys.argv[3] if len(sys.argv) >= 4 else "."

    # Collect student sources
    ex_glob = "../../ex*/*.c" if mode == "eval" else f"../../{target}/ex*/*.c"
    ex_files = sorted(glob.glob(ex_glob))
    if not ex_files:
        die(f"❌ No exercise .c files found for: {ex_glob}")

    # Collect test sources (stay in C; we just orchestrate)
    test_files = [os.path.join(testdir, n) for n in ("lib_C07.h","main.c","test_C07.c")]
    for f in test_files:
        if not os.path.isfile(f):
            die(f"❌ Missing test file: {f}")

    print(f"🧪 Tests from: {os.path.abspath(testdir)}")
    print("📦 Student sources:")
    for f in ex_files: print("  -", f)

    # Norminette (best effort)
    try:
        subprocess.run(["norminette", *ex_files, *(glob.glob(os.path.join(testdir, "*.c")))],
                       check=False, stdout=sys.stdout, stderr=sys.stderr)
    except FileNotFoundError:
        pass

    # Compile
    exe = "c07_tests.exe" if os.name == "nt" else "c07_tests"
    cmd = ["cc","-Wall","-Wextra","-Werror",
           os.path.join(testdir,"main.c"),
           os.path.join(testdir,"test_C07.c"),
           *ex_files,"-o",exe]
    print("⚙️  Compiling...")
    try:
        subprocess.run(cmd, check=True)
    except subprocess.CalledProcessError:
        die("❌ Compilation failed")

    # Run (Valgrind if available)
    v = shutil.which("valgrind")
    if v:
        print("🧠 Running under Valgrind...")
        res = subprocess.run([v,"--leak-check=full","--errors-for-leak-kinds=all","--error-exitcode=42","./"+exe])
        if res.returncode == 42:
            die("💥 Memory leak detected!", 42)
        sys.exit(res.returncode)
    else:
        print("⚠️ Valgrind not found, running normally.")
        sys.exit(subprocess.run(["./"+exe]).returncode)

if __name__ == "__main__":
    main()
