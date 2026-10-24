.setcpu "65816"
.segment "CODE"
.org $D1E3
map_control_0fd1e3:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
