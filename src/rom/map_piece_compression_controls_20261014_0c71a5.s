.setcpu "65816"
.segment "CODE"
.org $71A5
map_control_0c71a5:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
