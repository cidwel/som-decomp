.setcpu "65816"
.segment "CODE"
.org $5361
map_control_0d5361:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
