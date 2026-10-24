.setcpu "65816"
.segment "CODE"
.org $CE80
map_control_0fce80:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
