.setcpu "65816"
.segment "CODE"
.org $9FD0
map_control_0f9fd0:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
