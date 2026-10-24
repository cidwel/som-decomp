.setcpu "65816"
.segment "CODE"
.org $14E3
map_control_0f14e3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
