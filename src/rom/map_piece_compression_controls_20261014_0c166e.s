.setcpu "65816"
.segment "CODE"
.org $166E
map_control_0c166e:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
