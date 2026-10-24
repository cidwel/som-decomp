.setcpu "65816"
.segment "CODE"
.org $2F56
map_control_0c2f56:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
