.setcpu "65816"
.segment "CODE"
.org $5C45
map_control_0c5c45:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
