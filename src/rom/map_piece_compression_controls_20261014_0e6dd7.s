.setcpu "65816"
.segment "CODE"
.org $6DD7
map_control_0e6dd7:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
