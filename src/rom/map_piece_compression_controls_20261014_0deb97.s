.setcpu "65816"
.segment "CODE"
.org $EB97
map_control_0deb97:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
