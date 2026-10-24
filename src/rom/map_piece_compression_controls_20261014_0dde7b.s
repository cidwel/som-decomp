.setcpu "65816"
.segment "CODE"
.org $DE7B
map_control_0dde7b:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
