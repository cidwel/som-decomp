.setcpu "65816"
.segment "CODE"
.org $3AA4
map_control_0f3aa4:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
