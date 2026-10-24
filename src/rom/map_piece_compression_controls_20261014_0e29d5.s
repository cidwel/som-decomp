.setcpu "65816"
.segment "CODE"
.org $29D5
map_control_0e29d5:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
