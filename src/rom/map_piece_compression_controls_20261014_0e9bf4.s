.setcpu "65816"
.segment "CODE"
.org $9BF4
map_control_0e9bf4:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
