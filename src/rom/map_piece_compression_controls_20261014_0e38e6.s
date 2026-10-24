.setcpu "65816"
.segment "CODE"
.org $38E6
map_control_0e38e6:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
