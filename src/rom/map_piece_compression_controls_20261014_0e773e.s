.setcpu "65816"
.segment "CODE"
.org $773E
map_control_0e773e:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
