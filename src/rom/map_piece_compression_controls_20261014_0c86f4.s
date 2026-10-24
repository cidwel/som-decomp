.setcpu "65816"
.segment "CODE"
.org $86F4
map_control_0c86f4:
    .byte $EE ; backreference distance high bits
    .byte $90 ; distance low bit/count
