.setcpu "65816"
.segment "CODE"
.org $1D8B
map_control_0f1d8b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
