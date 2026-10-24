.setcpu "65816"
.segment "CODE"
.org $CED9
map_control_0dced9:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
