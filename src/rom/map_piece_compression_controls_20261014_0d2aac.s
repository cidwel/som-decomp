.setcpu "65816"
.segment "CODE"
.org $2AAC
map_control_0d2aac:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
