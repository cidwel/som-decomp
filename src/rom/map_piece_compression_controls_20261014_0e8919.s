.setcpu "65816"
.segment "CODE"
.org $8919
map_control_0e8919:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
