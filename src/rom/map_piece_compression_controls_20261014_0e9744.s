.setcpu "65816"
.segment "CODE"
.org $9744
map_control_0e9744:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
