.setcpu "65816"
.segment "CODE"
.org $23D0
map_control_0f23d0:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
