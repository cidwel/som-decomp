.setcpu "65816"
.segment "CODE"
.org $521E
map_control_0c521e:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
