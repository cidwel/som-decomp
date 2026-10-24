.setcpu "65816"
.segment "CODE"
.org $24F0
map_control_0f24f0:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
