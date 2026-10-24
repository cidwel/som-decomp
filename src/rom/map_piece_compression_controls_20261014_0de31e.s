.setcpu "65816"
.segment "CODE"
.org $E31E
map_control_0de31e:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
