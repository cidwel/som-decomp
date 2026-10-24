.setcpu "65816"
.segment "CODE"
.org $5FD5
map_control_0f5fd5:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
