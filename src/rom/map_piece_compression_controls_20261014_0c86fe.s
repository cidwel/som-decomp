.setcpu "65816"
.segment "CODE"
.org $86FE
map_control_0c86fe:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
