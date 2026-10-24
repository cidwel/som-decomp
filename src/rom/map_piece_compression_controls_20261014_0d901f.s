.setcpu "65816"
.segment "CODE"
.org $901F
map_control_0d901f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
