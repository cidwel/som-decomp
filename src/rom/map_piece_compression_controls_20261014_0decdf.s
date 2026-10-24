.setcpu "65816"
.segment "CODE"
.org $ECDF
map_control_0decdf:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
