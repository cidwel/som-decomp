.setcpu "65816"
.segment "CODE"
.org $3FC1
map_control_0c3fc1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
