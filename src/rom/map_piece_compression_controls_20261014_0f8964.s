.setcpu "65816"
.segment "CODE"
.org $8964
map_control_0f8964:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
