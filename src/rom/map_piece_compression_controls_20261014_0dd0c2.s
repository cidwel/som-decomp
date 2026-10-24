.setcpu "65816"
.segment "CODE"
.org $D0C2
map_control_0dd0c2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
