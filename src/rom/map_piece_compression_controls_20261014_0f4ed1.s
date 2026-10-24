.setcpu "65816"
.segment "CODE"
.org $4ED1
map_control_0f4ed1:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
