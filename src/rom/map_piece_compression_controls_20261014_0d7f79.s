.setcpu "65816"
.segment "CODE"
.org $7F79
map_control_0d7f79:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
