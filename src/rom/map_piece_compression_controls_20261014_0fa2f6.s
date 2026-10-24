.setcpu "65816"
.segment "CODE"
.org $A2F6
map_control_0fa2f6:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
