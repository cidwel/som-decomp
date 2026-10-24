.setcpu "65816"
.segment "CODE"
.org $9D51
map_control_0f9d51:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
