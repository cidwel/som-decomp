.setcpu "65816"
.segment "CODE"
.org $3A9A
map_control_0f3a9a:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
