.setcpu "65816"
.segment "CODE"
.org $19B3
map_control_0e19b3:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
