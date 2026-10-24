.setcpu "65816"
.segment "CODE"
.org $A318
map_control_0fa318:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
