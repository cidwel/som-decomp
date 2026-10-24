.setcpu "65816"
.segment "CODE"
.org $99EE
map_control_0d99ee:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
