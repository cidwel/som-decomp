.setcpu "65816"
.segment "CODE"
.org $B45A
map_control_0eb45a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
