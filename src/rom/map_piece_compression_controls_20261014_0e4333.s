.setcpu "65816"
.segment "CODE"
.org $4333
map_control_0e4333:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
