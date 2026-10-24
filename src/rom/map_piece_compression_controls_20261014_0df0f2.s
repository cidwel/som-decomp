.setcpu "65816"
.segment "CODE"
.org $F0F2
map_control_0df0f2:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
