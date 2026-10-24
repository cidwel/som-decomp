.setcpu "65816"
.segment "CODE"
.org $2E66
map_control_0f2e66:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
