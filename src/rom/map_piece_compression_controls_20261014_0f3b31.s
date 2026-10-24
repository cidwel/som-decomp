.setcpu "65816"
.segment "CODE"
.org $3B31
map_control_0f3b31:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
