.setcpu "65816"
.segment "CODE"
.org $A8D7
map_control_0fa8d7:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
