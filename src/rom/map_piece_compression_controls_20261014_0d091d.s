.setcpu "65816"
.segment "CODE"
.org $091D
map_control_0d091d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
