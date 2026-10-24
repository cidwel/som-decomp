.setcpu "65816"
.segment "CODE"
.org $10BE
map_control_0c10be:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
