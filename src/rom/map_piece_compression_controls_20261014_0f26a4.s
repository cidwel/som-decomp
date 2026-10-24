.setcpu "65816"
.segment "CODE"
.org $26A4
map_control_0f26a4:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
