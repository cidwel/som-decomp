.setcpu "65816"
.segment "CODE"
.org $AFEB
map_control_0dafeb:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
