.setcpu "65816"
.segment "CODE"
.org $3358
map_control_0e3358:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
