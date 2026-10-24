.setcpu "65816"
.segment "CODE"
.org $F407
map_control_0df407:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
