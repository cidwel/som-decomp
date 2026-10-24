.setcpu "65816"
.segment "CODE"
.org $4689
map_control_0f4689:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
