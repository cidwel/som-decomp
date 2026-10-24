.setcpu "65816"
.segment "CODE"
.org $9A49
map_control_0e9a49:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
