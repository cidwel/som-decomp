.setcpu "65816"
.segment "CODE"
.org $BC03
map_control_0fbc03:
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
