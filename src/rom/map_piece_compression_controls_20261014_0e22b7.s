.setcpu "65816"
.segment "CODE"
.org $22B7
map_control_0e22b7:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
