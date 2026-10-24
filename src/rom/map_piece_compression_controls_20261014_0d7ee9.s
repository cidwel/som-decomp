.setcpu "65816"
.segment "CODE"
.org $7EE9
map_control_0d7ee9:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
