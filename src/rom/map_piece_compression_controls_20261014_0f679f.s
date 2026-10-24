.setcpu "65816"
.segment "CODE"
.org $679F
map_control_0f679f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
