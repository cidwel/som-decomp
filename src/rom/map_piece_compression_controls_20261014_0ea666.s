.setcpu "65816"
.segment "CODE"
.org $A666
map_control_0ea666:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
