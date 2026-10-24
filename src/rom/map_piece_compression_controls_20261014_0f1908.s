.setcpu "65816"
.segment "CODE"
.org $1908
map_control_0f1908:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
