.setcpu "65816"
.segment "CODE"
.org $62FD
map_control_0f62fd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
