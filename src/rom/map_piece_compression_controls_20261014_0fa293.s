.setcpu "65816"
.segment "CODE"
.org $A293
map_control_0fa293:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
