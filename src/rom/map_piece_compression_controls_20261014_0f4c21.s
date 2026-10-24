.setcpu "65816"
.segment "CODE"
.org $4C21
map_control_0f4c21:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
