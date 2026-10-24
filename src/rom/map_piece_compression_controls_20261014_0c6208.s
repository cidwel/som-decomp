.setcpu "65816"
.segment "CODE"
.org $6208
map_control_0c6208:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
