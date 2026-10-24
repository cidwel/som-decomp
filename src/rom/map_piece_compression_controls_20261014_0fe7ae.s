.setcpu "65816"
.segment "CODE"
.org $E7AE
map_control_0fe7ae:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
