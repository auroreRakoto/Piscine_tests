#include "test_framework.h"

void	run_test_ft_strcpy()
{
	printf("========= ex00 =========\n");
	char	src1[] = "hello world!";
	char	dst_ft1[20] = {0};
	char	dst_ref1[20] = {0};
	char *ret_ft1 = ft_strcpy(dst_ft1, src1);
	char *ret_ref1 = strcpy(dst_ref1, src1);
	assert_str(ret_ref1, ret_ft1, "Test 1 - basic string");

	char	src2[] = "";
	char	dst_ft2[20] = {0};
	char	dst_ref2[20] = {0};
	char *ret_ft2 = ft_strcpy(dst_ft2, src2);
	char *ret_ref2 = strcpy(dst_ref2, src2);
	assert_str(ret_ref2, ret_ft2, "Test 2 - empty string");

	char	src3[] = "A";
	char	dst_ft3[40] = {0};
	char	dst_ref3[40] = {0};
	char *ret_ft3 = ft_strcpy(dst_ft3, src3);
	char *ret_ref3 = strcpy(dst_ref3, src3);
	assert_str(ret_ref3, ret_ft3, "Test 3 - single character string");

	char	src4[] = "sefef/fsf;e'sesf./.se[f';'f..5$&K&$^L$M]";
	char	dst_ft4[40] = {0};
	char	dst_ref4[40] = {0};
	char *ret_ft4 = ft_strcpy(dst_ft4, src4);
	char *ret_ref4 = strcpy(dst_ref4, src4);
	assert_str(ret_ref4, ret_ft4, "Test 4 - special symbols string");

	char	src5[] = "Lorem ipsum dolor sit\0 amet, consectetur adipiscing elit.";
	char	dst_ft5[40] = {0};
	char	dst_ref5[40] = {0};
	char *ret_ft5 = ft_strcpy(dst_ft5, src5);
	char *ret_ref5 = strcpy(dst_ref5, src5);
	assert_str(ret_ref5, ret_ft5, "Test 5 - \\0 string");

	char	src6[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla vehicula et nulla in mollis. Donec at neque nisl. Quisque lacus magna, bibendum eget nulla eu, iaculis tempor neque. Sed congue lorem molestie tortor blandit, sed eleifend nibh iaculis. Fusce ac sodales nisi. Duis consequat, mauris ac eleifend ullamcorper, enim nunc pharetra urna, sodales sollicitudin ligula ante in lacus. Suspendisse potenti. Pellentesque erat ligula, pretium at efficitur et, dignissim vel purus. Sed fermentum, nisi nec vestibulum vestibulum, enim mi suscipit diam, sit amet iaculis orci augue a lacus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec arcu nisi, \
	sagittis eget posuere eu, bibendum et velit. Mauris varius facilisis lectus at vulputate.\
	Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Praesent magna ligula, venenatis sed egestas vel, varius mollis urna. Vivamus accumsan nulla nec ipsum dictum, vitae ullamcorper dui volutpat. Cras eleifend sed nunc eu tempus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed mattis metus vitae metus commodo euismod. Morbi auctor, orci consequat dictum maximus, nisi lectus elementum ipsum, ac viverra lectus ipsum nec lorem. Donec fringilla, enim euismod varius accumsan, mi nulla efficitur est, et aliquet tortor ipsum id sapien. Sed sodales risus augue, quis viverra mauris ornare quis. Etiam sit amet nulla et purus ornare dapibus non a metus.\
	Donec pellentesque at magna at scelerisque. Ut ultricies felis sed dolor facilisis faucibus. Donec non semper ipsum. Morbi placerat convallis facilisis. In pretium gravida convallis. Ut ut eros ornare odio viverra rutrum. Phasellus luctus erat sit amet posuere maximus. Vestibulum sollicitudin a augue accumsan volutpat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec ornare mi quis diam fringilla, ut convallis nisl condimentum. Quisque tristique sodales luctus. Praesent vestibulum dui ut duis.";
	char	dst_ft6[10000] = {0};
	char	dst_ref6[10000] = {0};
	char *ret_ft6 = ft_strcpy(dst_ft6, src6);
	char *ret_ref6 = strcpy(dst_ref6, src6);
	assert_str(ret_ref6, ret_ft6, "Test 6 - big string");
}