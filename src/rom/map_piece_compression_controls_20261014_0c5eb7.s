.setcpu "65816"
.segment "CODE"
.org $5EB7
map_control_0c5eb7:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
