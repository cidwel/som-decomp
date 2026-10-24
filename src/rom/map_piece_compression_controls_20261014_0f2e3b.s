.setcpu "65816"
.segment "CODE"
.org $2E3B
map_control_0f2e3b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
