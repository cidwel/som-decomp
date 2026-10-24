.setcpu "65816"
.segment "CODE"
.org $37DC
map_control_0d37dc:
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
