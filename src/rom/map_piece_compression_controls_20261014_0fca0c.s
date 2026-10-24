.setcpu "65816"
.segment "CODE"
.org $CA0C
map_control_0fca0c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
