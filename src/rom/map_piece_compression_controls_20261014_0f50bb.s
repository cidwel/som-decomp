.setcpu "65816"
.segment "CODE"
.org $50BB
map_control_0f50bb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
