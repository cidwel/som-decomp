.setcpu "65816"
.segment "CODE"
.org $90DF
map_control_0c90df:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
