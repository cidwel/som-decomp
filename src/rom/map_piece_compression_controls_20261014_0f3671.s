.setcpu "65816"
.segment "CODE"
.org $3671
map_control_0f3671:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
