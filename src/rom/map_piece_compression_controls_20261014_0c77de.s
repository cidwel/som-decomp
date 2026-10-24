.setcpu "65816"
.segment "CODE"
.org $77DE
map_control_0c77de:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
