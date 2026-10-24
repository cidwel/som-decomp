.setcpu "65816"
.segment "CODE"
.org $5DF0
map_control_0e5df0:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
