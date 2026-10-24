.setcpu "65816"
.segment "CODE"
.org $9302
map_control_0f9302:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
