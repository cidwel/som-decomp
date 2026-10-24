.setcpu "65816"
.segment "CODE"
.org $31FB
map_control_0c31fb:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
