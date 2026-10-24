.setcpu "65816"
.segment "CODE"
.org $5287
map_control_0e5287:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
