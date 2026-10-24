.setcpu "65816"
.segment "CODE"
.org $A1B0
map_control_0fa1b0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
