.setcpu "65816"
.segment "CODE"
.org $A9AD
map_control_0ea9ad:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
