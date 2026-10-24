.setcpu "65816"
.segment "CODE"
.org $29A7
map_control_0c29a7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
