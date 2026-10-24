.setcpu "65816"
.segment "CODE"
.org $75BD
map_control_0f75bd:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
