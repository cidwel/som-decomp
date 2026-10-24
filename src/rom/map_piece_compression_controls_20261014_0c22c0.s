.setcpu "65816"
.segment "CODE"
.org $22C0
map_control_0c22c0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
