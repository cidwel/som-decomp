.setcpu "65816"
.segment "CODE"
.org $5448
map_control_0d5448:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
