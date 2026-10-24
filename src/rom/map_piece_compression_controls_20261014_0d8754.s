.setcpu "65816"
.segment "CODE"
.org $8754
map_control_0d8754:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
