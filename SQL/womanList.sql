-- https://school.programmers.co.kr/learn/courses/30/lessons/131120?language=oracle
-- 3월에 태어난 여성 회원 목록 출력하기 level 1


SELECT a.MEMBER_ID, a.MEMBER_NAME, a.GENDER, TO_CHAR(a.DATE_OF_BIRTH, 'YYYY-MM-DD') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE a
WHERE a.GENDER = 'W' AND TO_CHAR(a.DATE_OF_BIRTH, 'MM') = '03' AND TLNO IS NOT NULL
ORDER BY a.MEMBER_ID ASC;