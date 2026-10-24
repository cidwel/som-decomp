.setcpu "65816"
.segment "CODE"
.org $1380
map_control_0d1380:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
