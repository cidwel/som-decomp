.setcpu "65816"
.segment "CODE"
.org $D8A8
map_control_0dd8a8:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
