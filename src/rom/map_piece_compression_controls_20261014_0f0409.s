.setcpu "65816"
.segment "CODE"
.org $0409
map_control_0f0409:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
