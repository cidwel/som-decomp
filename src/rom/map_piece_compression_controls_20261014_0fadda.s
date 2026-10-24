.setcpu "65816"
.segment "CODE"
.org $ADDA
map_control_0fadda:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
