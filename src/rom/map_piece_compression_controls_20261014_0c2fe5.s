.setcpu "65816"
.segment "CODE"
.org $2FE5
map_control_0c2fe5:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
