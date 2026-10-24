.setcpu "65816"
.segment "CODE"
.org $A893
map_control_0fa893:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
