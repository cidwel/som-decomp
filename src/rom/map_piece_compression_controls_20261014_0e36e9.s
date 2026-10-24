.setcpu "65816"
.segment "CODE"
.org $36E9
map_control_0e36e9:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
