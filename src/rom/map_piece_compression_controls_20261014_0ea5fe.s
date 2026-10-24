.setcpu "65816"
.segment "CODE"
.org $A5FE
map_control_0ea5fe:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
