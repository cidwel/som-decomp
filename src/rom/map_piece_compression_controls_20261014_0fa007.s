.setcpu "65816"
.segment "CODE"
.org $A007
map_control_0fa007:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
