.setcpu "65816"
.segment "CODE"
.org $3445
map_control_0f3445:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
