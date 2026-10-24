.setcpu "65816"
.segment "CODE"
.org $4541
map_control_0f4541:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
