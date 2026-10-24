.setcpu "65816"
.segment "CODE"
.org $B50B
map_control_0fb50b:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
