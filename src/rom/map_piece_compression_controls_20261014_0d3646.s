.setcpu "65816"
.segment "CODE"
.org $3646
map_control_0d3646:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
