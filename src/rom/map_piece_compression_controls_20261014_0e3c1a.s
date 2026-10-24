.setcpu "65816"
.segment "CODE"
.org $3C1A
map_control_0e3c1a:
    .byte $E1 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
