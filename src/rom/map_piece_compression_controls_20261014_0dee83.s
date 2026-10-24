.setcpu "65816"
.segment "CODE"
.org $EE83
map_control_0dee83:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
