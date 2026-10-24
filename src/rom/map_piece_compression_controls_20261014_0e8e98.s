.setcpu "65816"
.segment "CODE"
.org $8E98
map_control_0e8e98:
    .byte $ED ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
