.setcpu "65816"
.segment "CODE"
.org $E246
map_control_0fe246:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
