.setcpu "65816"
.segment "CODE"
.org $A1A7
map_control_0fa1a7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
