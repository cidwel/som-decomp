.setcpu "65816"
.segment "CODE"
.org $CFE2
map_control_0dcfe2:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
