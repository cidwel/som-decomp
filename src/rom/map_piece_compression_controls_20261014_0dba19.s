.setcpu "65816"
.segment "CODE"
.org $BA19
map_control_0dba19:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
