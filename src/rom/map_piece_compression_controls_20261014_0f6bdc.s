.setcpu "65816"
.segment "CODE"
.org $6BDC
map_control_0f6bdc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
