.setcpu "65816"
.segment "CODE"
.org $2E79
map_control_0f2e79:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
