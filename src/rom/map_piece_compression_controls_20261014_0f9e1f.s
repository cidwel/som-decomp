.setcpu "65816"
.segment "CODE"
.org $9E1F
map_control_0f9e1f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
