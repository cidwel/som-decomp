.setcpu "65816"
.segment "CODE"
.org $EFAE
map_control_0eefae:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
