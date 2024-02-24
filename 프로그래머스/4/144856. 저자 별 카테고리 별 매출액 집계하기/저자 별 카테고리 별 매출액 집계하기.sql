-- 코드를 입력하세요
SELECT
    A.AUTHOR_ID,
    A.AUTHOR_NAME,
    B.CATEGORY,
    SUM(B.PRICE * S.SALES) AS TOTAL_SALES
FROM
    AUTHOR AS A
INNER JOIN
    BOOK AS B
ON
    A.AUTHOR_ID = B.AUTHOR_ID
INNER JOIN
    BOOK_SALES AS S
ON
    B.BOOK_ID = S.BOOK_ID
WHERE
    YEAR(S.SALES_DATE) = 2022
AND
    MONTH(S.SALES_DATE) = 1
GROUP BY
    A.AUTHOR_ID,
    B.CATEGORY
ORDER BY
    A.AUTHOR_ID ASC,
    B.CATEGORY DESC
;
    