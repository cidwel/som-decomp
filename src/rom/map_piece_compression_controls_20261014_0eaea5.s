.setcpu "65816"
.segment "CODE"
.org $AEA5
map_control_0eaea5:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
