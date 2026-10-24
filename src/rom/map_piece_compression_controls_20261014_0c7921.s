.setcpu "65816"
.segment "CODE"
.org $7921
map_control_0c7921:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
