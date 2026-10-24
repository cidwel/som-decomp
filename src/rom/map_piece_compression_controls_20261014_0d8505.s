.setcpu "65816"
.segment "CODE"
.org $8505
map_control_0d8505:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
