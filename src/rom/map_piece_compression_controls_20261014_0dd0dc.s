.setcpu "65816"
.segment "CODE"
.org $D0DC
map_control_0dd0dc:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
