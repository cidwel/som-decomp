.setcpu "65816"
.segment "CODE"
.org $39D1
map_control_0f39d1:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
