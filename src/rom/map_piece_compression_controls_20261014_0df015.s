.setcpu "65816"
.segment "CODE"
.org $F015
map_control_0df015:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
