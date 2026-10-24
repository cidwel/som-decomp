.setcpu "65816"
.segment "CODE"
.org $75DB
map_control_0e75db:
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
