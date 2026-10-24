.setcpu "65816"
.segment "CODE"
.org $D0B2
map_control_0dd0b2:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
