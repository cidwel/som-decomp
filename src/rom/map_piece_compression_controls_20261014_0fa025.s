.setcpu "65816"
.segment "CODE"
.org $A025
map_control_0fa025:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
