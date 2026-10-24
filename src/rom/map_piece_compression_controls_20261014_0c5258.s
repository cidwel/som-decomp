.setcpu "65816"
.segment "CODE"
.org $5258
map_control_0c5258:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
