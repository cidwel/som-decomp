.setcpu "65816"
.segment "CODE"
.org $D0CD
map_control_0fd0cd:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
