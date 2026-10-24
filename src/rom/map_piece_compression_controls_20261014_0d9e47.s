.setcpu "65816"
.segment "CODE"
.org $9E47
map_control_0d9e47:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
