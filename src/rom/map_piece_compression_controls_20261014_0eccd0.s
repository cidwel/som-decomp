.setcpu "65816"
.segment "CODE"
.org $CCD0
map_control_0eccd0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
