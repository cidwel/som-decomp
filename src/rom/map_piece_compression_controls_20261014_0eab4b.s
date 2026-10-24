.setcpu "65816"
.segment "CODE"
.org $AB4B
map_control_0eab4b:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
