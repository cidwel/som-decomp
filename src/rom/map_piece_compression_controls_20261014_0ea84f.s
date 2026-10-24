.setcpu "65816"
.segment "CODE"
.org $A84F
map_control_0ea84f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
