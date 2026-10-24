.setcpu "65816"
.segment "CODE"
.org $7513
map_control_0c7513:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
