.setcpu "65816"
.segment "CODE"
.org $718F
map_control_0d718f:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
