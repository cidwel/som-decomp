.setcpu "65816"
.segment "CODE"
.org $8727
map_control_0c8727:
    .byte $EE ; backreference distance high bits
    .byte $90 ; distance low bit/count
