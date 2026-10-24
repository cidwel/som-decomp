.setcpu "65816"
.segment "CODE"
.org $DE69
map_control_0dde69:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
