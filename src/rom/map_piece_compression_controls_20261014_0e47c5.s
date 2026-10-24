.setcpu "65816"
.segment "CODE"
.org $47C5
map_control_0e47c5:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
