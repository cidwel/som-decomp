.setcpu "65816"
.segment "CODE"
.org $87FE
map_control_0e87fe:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
