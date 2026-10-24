.setcpu "65816"
.segment "CODE"
.org $0E52
map_control_0f0e52:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
