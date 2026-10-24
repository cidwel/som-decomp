.setcpu "65816"
.segment "CODE"
.org $448C
map_control_0c448c:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
