.setcpu "65816"
.segment "CODE"
.org $4797
map_control_0f4797:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
