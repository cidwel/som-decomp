.setcpu "65816"
.segment "CODE"
.org $7C22
map_control_0d7c22:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
