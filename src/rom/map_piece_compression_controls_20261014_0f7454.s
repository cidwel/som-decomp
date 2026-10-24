.setcpu "65816"
.segment "CODE"
.org $7454
map_control_0f7454:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
