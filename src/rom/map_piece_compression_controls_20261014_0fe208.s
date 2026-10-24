.setcpu "65816"
.segment "CODE"
.org $E208
map_control_0fe208:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
