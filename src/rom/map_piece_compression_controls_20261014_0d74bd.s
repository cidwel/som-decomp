.setcpu "65816"
.segment "CODE"
.org $74BD
map_control_0d74bd:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
