function is_prime(n) result(res)
    integer, intent(in) :: n
    integer :: res
    integer :: i

    if (n < 2) then
        res = 0
        return
    end if

    do i = 2, int(sqrt(real(n)))
        if (mod(n, i) == 0) then
            res = 0
            return
        end if
    end do

    res = 1
end function is_prime
