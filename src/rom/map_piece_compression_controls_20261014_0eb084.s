.setcpu "65816"
.segment "CODE"
.org $B084
map_control_0eb084:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
