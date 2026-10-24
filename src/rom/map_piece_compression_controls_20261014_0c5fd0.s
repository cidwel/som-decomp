.setcpu "65816"
.segment "CODE"
.org $5FD0
map_control_0c5fd0:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
