.setcpu "65816"
.segment "CODE"
.org $A1E1
map_control_0fa1e1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
