.setcpu "65816"
.segment "CODE"
.org $D1BE
map_control_0ed1be:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
