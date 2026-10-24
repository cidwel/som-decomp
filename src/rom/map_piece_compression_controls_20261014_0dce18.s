.setcpu "65816"
.segment "CODE"
.org $CE18
map_control_0dce18:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
