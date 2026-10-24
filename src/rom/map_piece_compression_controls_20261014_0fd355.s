.setcpu "65816"
.segment "CODE"
.org $D355
map_control_0fd355:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
