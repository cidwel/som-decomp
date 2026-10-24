.setcpu "65816"
.segment "CODE"
.org $A1D9
map_control_0fa1d9:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
