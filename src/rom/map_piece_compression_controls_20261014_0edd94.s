.setcpu "65816"
.segment "CODE"
.org $DD94
map_control_0edd94:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
