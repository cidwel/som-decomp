.setcpu "65816"
.segment "CODE"
.org $D3C6
map_control_0ed3c6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
