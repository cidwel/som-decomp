.setcpu "65816"
.segment "CODE"
.org $61FC
map_control_0f61fc:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
