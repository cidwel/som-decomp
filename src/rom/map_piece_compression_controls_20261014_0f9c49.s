.setcpu "65816"
.segment "CODE"
.org $9C49
map_control_0f9c49:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
