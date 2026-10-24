.setcpu "65816"
.segment "CODE"
.org $5A0A
map_control_0d5a0a:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
