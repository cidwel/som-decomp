.setcpu "65816"
.segment "CODE"
.org $3029
map_control_0e3029:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
