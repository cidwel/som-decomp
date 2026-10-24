.setcpu "65816"
.segment "CODE"
.org $737A
map_control_0d737a:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
