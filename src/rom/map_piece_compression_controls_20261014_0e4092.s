.setcpu "65816"
.segment "CODE"
.org $4092
map_control_0e4092:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
