.setcpu "65816"
.segment "CODE"
.org $A151
map_control_0da151:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
