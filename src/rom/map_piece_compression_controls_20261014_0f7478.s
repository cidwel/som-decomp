.setcpu "65816"
.segment "CODE"
.org $7478
map_control_0f7478:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
