.setcpu "65816"
.segment "CODE"
.org $8348
map_control_0d8348:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
