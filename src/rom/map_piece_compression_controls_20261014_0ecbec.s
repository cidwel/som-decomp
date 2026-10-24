.setcpu "65816"
.segment "CODE"
.org $CBEC
map_control_0ecbec:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
