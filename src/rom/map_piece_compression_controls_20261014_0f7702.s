.setcpu "65816"
.segment "CODE"
.org $7702
map_control_0f7702:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
