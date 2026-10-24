.setcpu "65816"
.segment "CODE"
.org $6EA9
map_control_0d6ea9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
