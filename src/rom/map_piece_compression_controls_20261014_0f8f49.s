.setcpu "65816"
.segment "CODE"
.org $8F49
map_control_0f8f49:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
