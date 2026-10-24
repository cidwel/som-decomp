.setcpu "65816"
.segment "CODE"
.org $2523
map_control_0d2523:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
