.setcpu "65816"
.segment "CODE"
.org $21C1
map_control_0e21c1:
    .byte $F2 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $8F ; distance low bit/count
