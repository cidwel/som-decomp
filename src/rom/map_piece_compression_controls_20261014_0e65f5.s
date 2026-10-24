.setcpu "65816"
.segment "CODE"
.org $65F5
map_control_0e65f5:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
