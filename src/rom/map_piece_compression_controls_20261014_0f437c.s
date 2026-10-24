.setcpu "65816"
.segment "CODE"
.org $437C
map_control_0f437c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
