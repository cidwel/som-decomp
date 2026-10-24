.setcpu "65816"
.segment "CODE"
.org $7B64
map_control_0e7b64:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
