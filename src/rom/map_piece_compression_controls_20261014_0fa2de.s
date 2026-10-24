.setcpu "65816"
.segment "CODE"
.org $A2DE
map_control_0fa2de:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
