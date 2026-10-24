.setcpu "65816"
.segment "CODE"
.org $22A4
map_control_0c22a4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
