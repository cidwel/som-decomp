.setcpu "65816"
.segment "CODE"
.org $4958
map_control_0e4958:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
