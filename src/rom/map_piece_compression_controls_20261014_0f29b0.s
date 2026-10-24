.setcpu "65816"
.segment "CODE"
.org $29B0
map_control_0f29b0:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
