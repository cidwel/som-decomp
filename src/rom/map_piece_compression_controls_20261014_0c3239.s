.setcpu "65816"
.segment "CODE"
.org $3239
map_control_0c3239:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
