.setcpu "65816"
.segment "CODE"
.org $CFB2
map_control_0ecfb2:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
