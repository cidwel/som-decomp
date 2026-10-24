.setcpu "65816"
.segment "CODE"
.org $A7AB
map_control_0fa7ab:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
