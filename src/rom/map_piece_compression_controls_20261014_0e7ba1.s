.setcpu "65816"
.segment "CODE"
.org $7BA1
map_control_0e7ba1:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
