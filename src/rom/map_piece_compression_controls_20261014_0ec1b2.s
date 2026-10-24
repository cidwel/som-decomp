.setcpu "65816"
.segment "CODE"
.org $C1B2
map_control_0ec1b2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
