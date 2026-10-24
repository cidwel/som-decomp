.setcpu "65816"
.segment "CODE"
.org $CCC9
map_control_0eccc9:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
