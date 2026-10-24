.setcpu "65816"
.segment "CODE"
.org $8D8F
map_control_0f8d8f:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
