.setcpu "65816"
.segment "CODE"
.org $8C27
map_control_0f8c27:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
