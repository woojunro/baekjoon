-- 코드를 작성해주세요
SELECT
    ID,
    EMAIL,
    FIRST_NAME,
    LAST_NAME
FROM
    DEVELOPERS
WHERE
    SKILL_CODE & (
        SELECT
            CODE
        FROM
            SKILLCODES
        WHERE
            NAME = 'Python'
    ) <> 0
    OR
    SKILL_CODE & (
        SELECT
            CODE
        FROM
            SKILLCODES
        WHERE
            NAME = 'C#'
    ) <> 0
ORDER BY
    ID ASC
;