.setcpu "65816"
.segment "CODE"
.org $89CC
map_control_0e89cc:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
