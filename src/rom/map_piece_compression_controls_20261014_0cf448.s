.setcpu "65816"
.segment "CODE"
.org $F448
map_control_0cf448:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
