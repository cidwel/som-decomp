.setcpu "65816"
.segment "CODE"
.org $371D
map_control_0c371d:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
