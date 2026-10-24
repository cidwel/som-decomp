.setcpu "65816"
.segment "CODE"
.org $DBE9
map_control_0ddbe9:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
