.setcpu "65816"
.segment "CODE"
.org $1934
map_control_0f1934:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
