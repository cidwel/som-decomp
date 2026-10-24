.setcpu "65816"
.segment "CODE"
.org $9D49
map_control_0f9d49:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
