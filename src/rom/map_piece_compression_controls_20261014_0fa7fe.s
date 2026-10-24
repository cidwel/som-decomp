.setcpu "65816"
.segment "CODE"
.org $A7FE
map_control_0fa7fe:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
