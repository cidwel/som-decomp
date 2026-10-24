.setcpu "65816"
.segment "CODE"
.org $AB3A
map_control_0eab3a:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
