.setcpu "65816"
.segment "CODE"
.org $A657
map_control_0ea657:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
