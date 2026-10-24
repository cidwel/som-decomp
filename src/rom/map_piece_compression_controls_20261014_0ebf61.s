.setcpu "65816"
.segment "CODE"
.org $BF61
map_control_0ebf61:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
