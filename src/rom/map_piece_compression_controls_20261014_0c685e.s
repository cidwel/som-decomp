.setcpu "65816"
.segment "CODE"
.org $685E
map_control_0c685e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
