.setcpu "65816"
.segment "CODE"
.org $6E54
map_control_0e6e54:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
