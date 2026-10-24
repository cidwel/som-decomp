.setcpu "65816"
.segment "CODE"
.org $9D21
map_control_0f9d21:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
