.setcpu "65816"
.segment "CODE"
.org $40DE
map_control_0e40de:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
