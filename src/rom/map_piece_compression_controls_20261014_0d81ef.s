.setcpu "65816"
.segment "CODE"
.org $81EF
map_control_0d81ef:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
