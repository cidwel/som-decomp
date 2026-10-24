.setcpu "65816"
.segment "CODE"
.org $8D36
map_control_0f8d36:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
