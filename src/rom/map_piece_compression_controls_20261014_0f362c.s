.setcpu "65816"
.segment "CODE"
.org $362C
map_control_0f362c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
