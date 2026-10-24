.setcpu "65816"
.segment "CODE"
.org $F2C3
map_control_0ff2c3:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
