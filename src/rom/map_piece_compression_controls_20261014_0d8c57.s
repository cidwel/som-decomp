.setcpu "65816"
.segment "CODE"
.org $8C57
map_control_0d8c57:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
