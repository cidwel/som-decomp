.setcpu "65816"
.segment "CODE"
.org $B1B9
map_control_0eb1b9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
