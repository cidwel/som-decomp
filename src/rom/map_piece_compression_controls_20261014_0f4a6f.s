.setcpu "65816"
.segment "CODE"
.org $4A6F
map_control_0f4a6f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
