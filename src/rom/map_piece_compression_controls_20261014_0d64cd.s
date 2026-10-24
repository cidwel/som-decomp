.setcpu "65816"
.segment "CODE"
.org $64CD
map_control_0d64cd:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
