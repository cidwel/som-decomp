.setcpu "65816"
.segment "CODE"
.org $481A
map_control_0c481a:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
