.setcpu "65816"
.segment "CODE"
.org $524D
map_control_0f524d:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
