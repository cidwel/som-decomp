.setcpu "65816"
.segment "CODE"
.org $D834
map_control_0fd834:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
