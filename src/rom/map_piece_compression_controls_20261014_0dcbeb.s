.setcpu "65816"
.segment "CODE"
.org $CBEB
map_control_0dcbeb:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
