.setcpu "65816"
.segment "CODE"
.org $26A9
map_control_0f26a9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
