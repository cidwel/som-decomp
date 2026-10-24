.setcpu "65816"
.segment "CODE"
.org $2964
map_control_0f2964:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
