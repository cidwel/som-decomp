.setcpu "65816"
.segment "CODE"
.org $438E
map_control_0d438e:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
