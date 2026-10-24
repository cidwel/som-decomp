.setcpu "65816"
.segment "CODE"
.org $2AAC
map_control_0f2aac:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
