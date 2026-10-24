.setcpu "65816"
.segment "CODE"
.org $2002
map_control_0c2002:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
