.setcpu "65816"
.segment "CODE"
.org $E44F
map_control_0de44f:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $CC ; same-value copy count/distance
