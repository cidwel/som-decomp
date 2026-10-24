.setcpu "65816"
.segment "CODE"
.org $8BAC
map_control_0c8bac:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
