.setcpu "65816"
.segment "CODE"
.org $DD44
map_control_0edd44:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
