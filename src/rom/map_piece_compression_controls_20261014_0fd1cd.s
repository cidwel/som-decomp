.setcpu "65816"
.segment "CODE"
.org $D1CD
map_control_0fd1cd:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
