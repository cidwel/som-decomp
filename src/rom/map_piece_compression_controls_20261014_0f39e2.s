.setcpu "65816"
.segment "CODE"
.org $39E2
map_control_0f39e2:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
