.setcpu "65816"
.segment "CODE"
.org $6ED1
map_control_0e6ed1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
