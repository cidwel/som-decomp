.setcpu "65816"
.segment "CODE"
.org $9FD9
map_control_0f9fd9:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
