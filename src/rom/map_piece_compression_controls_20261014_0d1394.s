.setcpu "65816"
.segment "CODE"
.org $1394
map_control_0d1394:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
