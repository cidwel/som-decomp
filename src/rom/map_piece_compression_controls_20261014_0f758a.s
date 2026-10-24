.setcpu "65816"
.segment "CODE"
.org $758A
map_control_0f758a:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4C ; distance low bit/count
