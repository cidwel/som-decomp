.setcpu "65816"
.segment "CODE"
.org $1FB6
map_control_0c1fb6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
