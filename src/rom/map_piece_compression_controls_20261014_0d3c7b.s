.setcpu "65816"
.segment "CODE"
.org $3C7B
map_control_0d3c7b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
