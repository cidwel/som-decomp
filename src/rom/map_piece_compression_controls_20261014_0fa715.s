.setcpu "65816"
.segment "CODE"
.org $A715
map_control_0fa715:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
