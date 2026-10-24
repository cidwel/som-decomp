.setcpu "65816"
.segment "CODE"
.org $B37C
map_control_0eb37c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
