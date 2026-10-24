.setcpu "65816"
.segment "CODE"
.org $9133
map_control_0f9133:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
