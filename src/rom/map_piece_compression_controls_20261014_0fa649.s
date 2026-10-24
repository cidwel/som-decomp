.setcpu "65816"
.segment "CODE"
.org $A649
map_control_0fa649:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
