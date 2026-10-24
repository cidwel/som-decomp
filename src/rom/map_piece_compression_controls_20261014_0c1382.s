.setcpu "65816"
.segment "CODE"
.org $1382
map_control_0c1382:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
