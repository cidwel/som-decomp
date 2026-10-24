.setcpu "65816"
.segment "CODE"
.org $7E52
map_control_0f7e52:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
