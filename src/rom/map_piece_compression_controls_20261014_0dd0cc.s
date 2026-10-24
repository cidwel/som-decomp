.setcpu "65816"
.segment "CODE"
.org $D0CC
map_control_0dd0cc:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
