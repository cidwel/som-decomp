.setcpu "65816"
.segment "CODE"
.org $B1FF
map_control_0db1ff:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
