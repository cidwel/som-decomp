.setcpu "65816"
.segment "CODE"
.org $46B9
map_control_0f46b9:
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
