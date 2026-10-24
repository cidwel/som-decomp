.setcpu "65816"
.segment "CODE"
.org $5212
map_control_0e5212:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
