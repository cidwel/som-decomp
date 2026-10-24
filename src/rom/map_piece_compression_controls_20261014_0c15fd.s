.setcpu "65816"
.segment "CODE"
.org $15FD
map_control_0c15fd:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
