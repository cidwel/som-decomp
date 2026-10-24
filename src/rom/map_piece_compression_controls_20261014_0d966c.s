.setcpu "65816"
.segment "CODE"
.org $966C
map_control_0d966c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
