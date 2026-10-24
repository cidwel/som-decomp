.setcpu "65816"
.segment "CODE"
.org $1C1E
map_control_0d1c1e:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
