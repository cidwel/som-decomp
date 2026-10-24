.setcpu "65816"
.segment "CODE"
.org $1372
map_control_0d1372:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
