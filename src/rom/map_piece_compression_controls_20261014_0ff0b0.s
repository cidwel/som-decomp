.setcpu "65816"
.segment "CODE"
.org $F0B0
map_control_0ff0b0:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
