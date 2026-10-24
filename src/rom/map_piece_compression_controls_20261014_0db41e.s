.setcpu "65816"
.segment "CODE"
.org $B41E
map_control_0db41e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
