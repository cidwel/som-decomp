.setcpu "65816"
.segment "CODE"
.org $7CD8
map_control_0d7cd8:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E4 ; previous-row copy count
