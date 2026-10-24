.setcpu "65816"
.segment "CODE"
.org $BD9D
map_control_0ebd9d:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
