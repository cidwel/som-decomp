.setcpu "65816"
.segment "CODE"
.org $EE21
map_control_0fee21:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
