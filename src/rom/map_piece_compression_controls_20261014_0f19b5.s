.setcpu "65816"
.segment "CODE"
.org $19B5
map_control_0f19b5:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
