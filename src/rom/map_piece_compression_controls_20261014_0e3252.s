.setcpu "65816"
.segment "CODE"
.org $3252
map_control_0e3252:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
