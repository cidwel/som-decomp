.setcpu "65816"
.segment "CODE"
.org $9296
map_control_0c9296:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
