.setcpu "65816"
.segment "CODE"
.org $6ACF
map_control_0f6acf:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
