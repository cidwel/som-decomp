.setcpu "65816"
.segment "CODE"
.org $A113
map_control_0fa113:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
