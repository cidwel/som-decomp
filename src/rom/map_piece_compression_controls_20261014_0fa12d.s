.setcpu "65816"
.segment "CODE"
.org $A12D
map_control_0fa12d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
