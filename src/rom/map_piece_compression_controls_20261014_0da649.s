.setcpu "65816"
.segment "CODE"
.org $A649
map_control_0da649:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
