.setcpu "65816"
.segment "CODE"
.org $14D4
map_control_0d14d4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
