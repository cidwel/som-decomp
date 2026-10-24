.setcpu "65816"
.segment "CODE"
.org $1882
map_control_0c1882:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
