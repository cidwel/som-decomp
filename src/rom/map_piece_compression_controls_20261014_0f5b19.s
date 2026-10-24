.setcpu "65816"
.segment "CODE"
.org $5B19
map_control_0f5b19:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
