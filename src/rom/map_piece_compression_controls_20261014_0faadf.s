.setcpu "65816"
.segment "CODE"
.org $AADF
map_control_0faadf:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
