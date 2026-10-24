.setcpu "65816"
.segment "CODE"
.org $1501
map_control_0f1501:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
