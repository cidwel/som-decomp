.setcpu "65816"
.segment "CODE"
.org $7167
map_control_0f7167:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
