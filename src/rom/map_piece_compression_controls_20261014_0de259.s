.setcpu "65816"
.segment "CODE"
.org $E259
map_control_0de259:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
