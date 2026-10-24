.setcpu "65816"
.segment "CODE"
.org $91AD
map_control_0c91ad:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
