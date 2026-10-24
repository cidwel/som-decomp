.setcpu "65816"
.segment "CODE"
.org $B5DA
map_control_0fb5da:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
