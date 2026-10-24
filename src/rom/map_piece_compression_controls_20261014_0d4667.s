.setcpu "65816"
.segment "CODE"
.org $4667
map_control_0d4667:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
