.setcpu "65816"
.segment "CODE"
.org $1C76
map_control_0f1c76:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
