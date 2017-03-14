select max(salary)
from (
    select distinct S.*
    from Employee as S, Employee as T
    where S.salary < T.salary
)
