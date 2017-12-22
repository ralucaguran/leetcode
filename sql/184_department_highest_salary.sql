select d.Name as Department, e.Name as Employee, e.Salary 
from Employee e, Department d 
where (DepartmentId, Salary) in (
    select DepartmentId, max(salary) from Employee 
    group by DepartmentId)
and e.DepartmentId = d.Id;
