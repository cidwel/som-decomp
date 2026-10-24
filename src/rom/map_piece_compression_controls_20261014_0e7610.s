.setcpu "65816"
.segment "CODE"
.org $7610
map_control_0e7610:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
