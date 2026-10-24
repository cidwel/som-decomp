.setcpu "65816"
.segment "CODE"
.org $F572
map_control_0cf572:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E3 ; previous-row copy count
