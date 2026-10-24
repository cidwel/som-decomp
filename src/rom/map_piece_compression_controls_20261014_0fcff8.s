.setcpu "65816"
.segment "CODE"
.org $CFF8
map_control_0fcff8:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
