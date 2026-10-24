.setcpu "65816"
.segment "CODE"
.org $A8F3
map_control_0fa8f3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
