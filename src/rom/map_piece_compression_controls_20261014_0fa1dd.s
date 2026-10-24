.setcpu "65816"
.segment "CODE"
.org $A1DD
map_control_0fa1dd:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
