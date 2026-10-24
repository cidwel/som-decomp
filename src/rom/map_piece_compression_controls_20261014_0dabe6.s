.setcpu "65816"
.segment "CODE"
.org $ABE6
map_control_0dabe6:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
