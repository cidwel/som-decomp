.setcpu "65816"
.segment "CODE"
.org $A26A
map_control_0fa26a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
