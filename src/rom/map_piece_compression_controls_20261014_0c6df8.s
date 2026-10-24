.setcpu "65816"
.segment "CODE"
.org $6DF8
map_control_0c6df8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
