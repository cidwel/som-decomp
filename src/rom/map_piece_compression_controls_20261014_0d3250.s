.setcpu "65816"
.segment "CODE"
.org $3250
map_control_0d3250:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
