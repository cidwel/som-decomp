.setcpu "65816"
.segment "CODE"
.org $DFFA
map_control_0fdffa:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
