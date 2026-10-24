.setcpu "65816"
.segment "CODE"
.org $1676
map_control_0f1676:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
