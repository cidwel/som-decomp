.setcpu "65816"
.segment "CODE"
.org $F924
map_control_0ff924:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
