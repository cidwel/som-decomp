.setcpu "65816"
.segment "CODE"
.org $2A72
map_control_0e2a72:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
