.setcpu "65816"
.segment "CODE"
.org $B892
map_control_0eb892:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
