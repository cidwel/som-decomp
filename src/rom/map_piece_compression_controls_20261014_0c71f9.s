.setcpu "65816"
.segment "CODE"
.org $71F9
map_control_0c71f9:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
