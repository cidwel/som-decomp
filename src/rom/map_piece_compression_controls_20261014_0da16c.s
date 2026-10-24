.setcpu "65816"
.segment "CODE"
.org $A16C
map_control_0da16c:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
