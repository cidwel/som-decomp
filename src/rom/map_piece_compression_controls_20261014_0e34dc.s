.setcpu "65816"
.segment "CODE"
.org $34DC
map_control_0e34dc:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
