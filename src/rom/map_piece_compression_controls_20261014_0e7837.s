.setcpu "65816"
.segment "CODE"
.org $7837
map_control_0e7837:
    .byte $E0 ; previous-row copy escape
    .byte $58 ; row-distance/count
