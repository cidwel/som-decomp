.setcpu "65816"
.segment "CODE"
.org $66A7
map_control_0d66a7:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
