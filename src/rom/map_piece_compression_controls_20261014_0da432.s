.setcpu "65816"
.segment "CODE"
.org $A432
map_control_0da432:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
