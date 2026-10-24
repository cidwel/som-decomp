.setcpu "65816"
.segment "CODE"
.org $2752
map_control_0f2752:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $73 ; distance low bit/count
