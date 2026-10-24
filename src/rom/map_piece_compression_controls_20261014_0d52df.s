.setcpu "65816"
.segment "CODE"
.org $52DF
map_control_0d52df:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $6A ; distance low bit/count
