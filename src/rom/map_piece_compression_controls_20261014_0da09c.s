.setcpu "65816"
.segment "CODE"
.org $A09C
map_control_0da09c:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
