.setcpu "65816"
.segment "CODE"
.org $BC15
map_control_0fbc15:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
