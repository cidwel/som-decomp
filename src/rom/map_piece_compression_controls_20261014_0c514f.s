.setcpu "65816"
.segment "CODE"
.org $514F
map_control_0c514f:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
