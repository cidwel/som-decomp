.setcpu "65816"
.segment "CODE"
.org $87AB
map_control_0e87ab:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
