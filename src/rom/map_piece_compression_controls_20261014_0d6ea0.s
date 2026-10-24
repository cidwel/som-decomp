.setcpu "65816"
.segment "CODE"
.org $6EA0
map_control_0d6ea0:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
