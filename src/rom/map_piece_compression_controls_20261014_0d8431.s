.setcpu "65816"
.segment "CODE"
.org $8431
map_control_0d8431:
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
