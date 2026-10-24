.setcpu "65816"
.segment "CODE"
.org $39FD
map_control_0f39fd:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
