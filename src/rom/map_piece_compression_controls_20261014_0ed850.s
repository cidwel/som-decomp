.setcpu "65816"
.segment "CODE"
.org $D850
map_control_0ed850:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
