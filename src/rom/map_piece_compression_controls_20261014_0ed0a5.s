.setcpu "65816"
.segment "CODE"
.org $D0A5
map_control_0ed0a5:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
