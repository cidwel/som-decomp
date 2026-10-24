.setcpu "65816"
.segment "CODE"
.org $5200
map_control_0d5200:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
