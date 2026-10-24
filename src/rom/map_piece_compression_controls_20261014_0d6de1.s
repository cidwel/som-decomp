.setcpu "65816"
.segment "CODE"
.org $6DE1
map_control_0d6de1:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
