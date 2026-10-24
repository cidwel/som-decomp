.setcpu "65816"
.segment "CODE"
.org $7EB3
map_control_0d7eb3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
