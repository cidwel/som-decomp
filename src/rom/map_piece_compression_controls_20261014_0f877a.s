.setcpu "65816"
.segment "CODE"
.org $877A
map_control_0f877a:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
