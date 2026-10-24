.setcpu "65816"
.segment "CODE"
.org $5062
map_control_0c5062:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
