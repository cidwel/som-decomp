.setcpu "65816"
.segment "CODE"
.org $D975
map_control_0fd975:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
