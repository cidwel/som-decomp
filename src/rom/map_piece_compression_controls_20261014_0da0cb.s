.setcpu "65816"
.segment "CODE"
.org $A0CB
map_control_0da0cb:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E1 ; previous-row copy count
