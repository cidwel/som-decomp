.setcpu "65816"
.segment "CODE"
.org $569E
map_control_0e569e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
