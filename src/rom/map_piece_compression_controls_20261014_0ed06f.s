.setcpu "65816"
.segment "CODE"
.org $D06F
map_control_0ed06f:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
