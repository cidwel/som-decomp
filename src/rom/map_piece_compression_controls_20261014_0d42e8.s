.setcpu "65816"
.segment "CODE"
.org $42E8
map_control_0d42e8:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
