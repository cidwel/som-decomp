.setcpu "65816"
.segment "CODE"
.org $9DA8
map_control_0e9da8:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
