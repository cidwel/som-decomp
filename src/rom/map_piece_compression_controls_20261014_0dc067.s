.setcpu "65816"
.segment "CODE"
.org $C067
map_control_0dc067:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
