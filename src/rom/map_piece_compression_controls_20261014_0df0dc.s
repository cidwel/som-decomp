.setcpu "65816"
.segment "CODE"
.org $F0DC
map_control_0df0dc:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
