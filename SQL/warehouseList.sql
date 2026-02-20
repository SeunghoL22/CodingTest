-- https://school.programmers.co.kr/learn/courses/30/lessons/131114
-- 경기도에 위치한 식품창고 목록 출력하기

SELECT A.WAREHOUSE_ID, A.WAREHOUSE_NAME, A.ADDRESS, NVL(A.FREEZER_YN, 'N') AS FREEZER_YN
FROM FOOD_WAREHOUSE A
WHERE A.ADDRESS LIKE '경기도%'
ORDER BY A.WAREHOUSE_ID ASC
