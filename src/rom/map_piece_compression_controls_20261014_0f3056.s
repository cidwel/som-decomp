.setcpu "65816"
.segment "CODE"
.org $3056
map_control_0f3056:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
