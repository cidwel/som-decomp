.setcpu "65816"
.segment "CODE"
.org $A112
map_control_0ea112:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
