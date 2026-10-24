.setcpu "65816"
.segment "CODE"
.org $3953
map_control_0d3953:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
