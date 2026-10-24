.setcpu "65816"
.segment "CODE"
.org $5296
map_control_0d5296:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
