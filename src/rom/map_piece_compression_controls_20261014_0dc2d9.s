.setcpu "65816"
.segment "CODE"
.org $C2D9
map_control_0dc2d9:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
