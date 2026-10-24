.setcpu "65816"
.segment "CODE"
.org $F319
map_control_0df319:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
