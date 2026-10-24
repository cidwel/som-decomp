.setcpu "65816"
.segment "CODE"
.org $EC99
map_control_0eec99:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
