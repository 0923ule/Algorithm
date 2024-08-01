-- 코드를 입력하세요
SELECT a.CAR_ID, a.CAR_TYPE, ROUND(a.DAILY_FEE * 30 * (100 - c.DISCOUNT_RATE) / 100) as FEE
FROM CAR_RENTAL_COMPANY_CAR as A, CAR_RENTAL_COMPANY_RENTAL_HISTORY as B, CAR_RENTAL_COMPANY_DISCOUNT_PLAN as C

WHERE (a.CAR_TYPE = '세단' or a.CAR_TYPE = 'SUV')
and (a.CAR_ID = b.CAR_ID)
and a.CAR_ID NOT IN (
    SELECT b.CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY as B
    WHERE ((b.START_DATE >= '2022-11-01') and (b.START_DATE <= '2022-11-30')
    or (b.END_DATE >= '2022-11-01') and (b.END_DATE <= '2022-11-30')
    or (b.START_DATE <= '2022-11-01') and (b.END_DATE >= '2022-11-30'))
    )
and a.CAR_TYPE = c.CAR_TYPE
and c.DURATION_TYPE = '30일 이상'
GROUP BY a.CAR_ID
HAVING FEE >= 500000 and FEE <= 2000000
ORDER BY FEE DESC, a.CAR_TYPE, a.CAR_ID DESC