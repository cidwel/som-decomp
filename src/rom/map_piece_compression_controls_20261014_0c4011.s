.setcpu "65816"
.segment "CODE"
.org $4011
map_control_0c4011:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
