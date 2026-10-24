.setcpu "65816"
.segment "CODE"
.org $21BD
map_control_0f21bd:
    .byte $E0 ; previous-row copy escape
    .byte $6A ; row-distance/count
