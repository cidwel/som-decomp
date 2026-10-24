.setcpu "65816"
.segment "CODE"
.org $2983
map_control_0c2983:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
