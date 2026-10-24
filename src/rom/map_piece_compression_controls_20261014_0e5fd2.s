.setcpu "65816"
.segment "CODE"
.org $5FD2
map_control_0e5fd2:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
