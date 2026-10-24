.setcpu "65816"
.segment "CODE"
.org $3354
map_control_0e3354:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
