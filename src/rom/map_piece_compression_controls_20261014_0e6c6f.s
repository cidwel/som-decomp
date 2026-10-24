.setcpu "65816"
.segment "CODE"
.org $6C6F
map_control_0e6c6f:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
