.setcpu "65816"
.segment "CODE"
.org $8C71
map_control_0f8c71:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
