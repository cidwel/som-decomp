.setcpu "65816"
.segment "CODE"
.org $8B1B
map_control_0c8b1b:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
