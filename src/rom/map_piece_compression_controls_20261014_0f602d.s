.setcpu "65816"
.segment "CODE"
.org $602D
map_control_0f602d:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
