-- GROUP BY 즐겨찾기가 가장 많은 식당 정보 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131115
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM (
    SELECT A.*,
            RANK() OVER (PARTITION BY FOOD_TYPE ORDER BY FAVORITES DESC)
    FROM REST_INFO A
)
