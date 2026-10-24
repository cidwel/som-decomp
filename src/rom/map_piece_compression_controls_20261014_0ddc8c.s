.setcpu "65816"
.segment "CODE"
.org $DC8C
map_control_0ddc8c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
