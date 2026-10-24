.setcpu "65816"
.segment "CODE"
.org $D2A5
map_control_0fd2a5:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
