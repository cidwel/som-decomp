.setcpu "65816"
.segment "CODE"
.org $4484
map_control_0f4484:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
