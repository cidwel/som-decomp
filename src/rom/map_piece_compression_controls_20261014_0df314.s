.setcpu "65816"
.segment "CODE"
.org $F314
map_control_0df314:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
