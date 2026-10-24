.setcpu "65816"
.segment "CODE"
.org $3757
map_control_0f3757:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
