.setcpu "65816"
.segment "CODE"
.org $6529
map_control_0e6529:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
