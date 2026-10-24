.setcpu "65816"
.segment "CODE"
.org $425B
map_control_0c425b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
