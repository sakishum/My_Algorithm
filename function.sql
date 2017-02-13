select MOD(31, 8);		 -- 求模
select TRUNCATE(1.32, 1); -- 返回被四舍五入去除小数点 y 位的数字 x
select HEX('this is a test str');
select UNHEX('746869732069732061207465737420737472');
select CHAR_LENGTH('this is a test str');	-- 返回字符串长度
select CONCAT_WS('-', '1st', '2nd', '3rd'); -- 合并字符串，concat with separator
select LPAD('hello', 4, '??'), LPAD('hello', 10, '??'); -- 填充字符串函数
select TRIM(' hello '); -- 删除字符串 s 两侧的空格
select TRIM('xy' from 'xyxboxyokxxyxy');  -- 删除指定字符串的函数