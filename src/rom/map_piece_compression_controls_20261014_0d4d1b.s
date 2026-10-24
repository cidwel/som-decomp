.setcpu "65816"
.segment "CODE"
.org $4D1B
map_control_0d4d1b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
