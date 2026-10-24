.setcpu "65816"
.segment "CODE"
.org $8E16
map_control_0d8e16:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E3 ; previous-row copy count
