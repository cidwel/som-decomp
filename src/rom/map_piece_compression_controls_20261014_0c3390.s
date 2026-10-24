.setcpu "65816"
.segment "CODE"
.org $3390
map_control_0c3390:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
