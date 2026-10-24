.setcpu "65816"
.segment "CODE"
.org $0CB6
map_control_0e0cb6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
