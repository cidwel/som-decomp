.setcpu "65816"
.segment "CODE"
.org $A2AE
map_control_0fa2ae:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
