.setcpu "65816"
.segment "CODE"
.org $20F8
map_control_0e20f8:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
