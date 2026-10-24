.setcpu "65816"
.segment "CODE"
.org $1797
map_control_0f1797:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
