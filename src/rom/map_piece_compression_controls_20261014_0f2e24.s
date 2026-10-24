.setcpu "65816"
.segment "CODE"
.org $2E24
map_control_0f2e24:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
