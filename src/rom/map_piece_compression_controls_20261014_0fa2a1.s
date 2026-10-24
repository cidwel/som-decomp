.setcpu "65816"
.segment "CODE"
.org $A2A1
map_control_0fa2a1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
