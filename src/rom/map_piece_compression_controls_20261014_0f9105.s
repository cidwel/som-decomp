.setcpu "65816"
.segment "CODE"
.org $9105
map_control_0f9105:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
