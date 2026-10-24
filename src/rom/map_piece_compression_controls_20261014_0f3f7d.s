.setcpu "65816"
.segment "CODE"
.org $3F7D
map_control_0f3f7d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
