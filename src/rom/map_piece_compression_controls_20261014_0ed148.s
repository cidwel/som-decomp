.setcpu "65816"
.segment "CODE"
.org $D148
map_control_0ed148:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
