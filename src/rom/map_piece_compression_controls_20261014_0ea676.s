.setcpu "65816"
.segment "CODE"
.org $A676
map_control_0ea676:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
