.setcpu "65816"
.segment "CODE"
.org $8E3C
map_control_0d8e3c:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
