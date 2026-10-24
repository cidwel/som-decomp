.setcpu "65816"
.segment "CODE"
.org $1AAF
map_control_0c1aaf:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
