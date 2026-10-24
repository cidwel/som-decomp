.setcpu "65816"
.segment "CODE"
.org $6BF1
map_control_0f6bf1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
