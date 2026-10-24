.setcpu "65816"
.segment "CODE"
.org $6FF9
map_control_0c6ff9:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
