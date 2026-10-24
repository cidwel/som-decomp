.setcpu "65816"
.segment "CODE"
.org $5875
map_control_0c5875:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
