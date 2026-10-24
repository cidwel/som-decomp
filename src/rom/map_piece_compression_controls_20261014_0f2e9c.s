.setcpu "65816"
.segment "CODE"
.org $2E9C
map_control_0f2e9c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
