.setcpu "65816"
.segment "CODE"
.org $D7D5
map_control_0ed7d5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
