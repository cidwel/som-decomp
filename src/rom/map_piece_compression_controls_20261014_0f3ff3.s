.setcpu "65816"
.segment "CODE"
.org $3FF3
map_control_0f3ff3:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
