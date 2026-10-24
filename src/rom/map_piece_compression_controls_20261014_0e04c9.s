.setcpu "65816"
.segment "CODE"
.org $04C9
map_control_0e04c9:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
