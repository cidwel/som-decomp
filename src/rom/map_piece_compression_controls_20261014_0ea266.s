.setcpu "65816"
.segment "CODE"
.org $A266
map_control_0ea266:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
