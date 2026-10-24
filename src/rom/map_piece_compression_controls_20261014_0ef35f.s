.setcpu "65816"
.segment "CODE"
.org $F35F
map_control_0ef35f:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
