.setcpu "65816"
.segment "CODE"
.org $F551
map_control_0cf551:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
