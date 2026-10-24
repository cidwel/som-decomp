.setcpu "65816"
.segment "CODE"
.org $A753
map_control_0da753:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
