.setcpu "65816"
.segment "CODE"
.org $65D5
map_control_0c65d5:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
