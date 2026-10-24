.setcpu "65816"
.segment "CODE"
.org $1A07
map_control_0e1a07:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
