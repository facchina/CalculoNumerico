!raciocinio:
!f(x) = n, onde n = 0 (zero da funcao)
!n = raiz(input) 
!n - raiz(input) = 0
!n^2 - input = 0 -> formula!

program bissec
    implicit none 
    integer :: n 
    real :: input, a, b, midpoint, fmidpoint
    real :: error = 1E-6
    
    READ*, input 
    if (input < 0) then
        !print*, "input must be greater then 0"
        stop
    end if
    b = input 

    do while (n < 100)
        midpoint = (a+b)/2
        fmidpoint = (midpoint*midpoint) - input
        
        if (abs((b-a)/2) < error .OR. fmidpoint == 0) then
            exit 
        end if

        if (fmidpoint > 0) then
            b = midpoint
        else 
            a = midpoint
        end if      

        n = n + 1
    end do
    print*, midpoint
end program bissec 