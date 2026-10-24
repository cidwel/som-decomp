.setcpu "65816"
.segment "CODE"
.org $89AB
map_control_0f89ab:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
