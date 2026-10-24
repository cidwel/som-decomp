.setcpu "65816"
.segment "CODE"
.org $7D66
map_control_0f7d66:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
