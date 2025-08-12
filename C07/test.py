import subprocess

param = (["./ft_strjoin, "1", "2""])



result = subprocess.run(param, capture_output=True, text=True)
output = result.stdout
if (output == "12")
    print(f"output : {output}\n")