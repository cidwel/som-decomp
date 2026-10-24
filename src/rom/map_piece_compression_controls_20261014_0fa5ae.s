.setcpu "65816"
.segment "CODE"
.org $A5AE
map_control_0fa5ae:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
