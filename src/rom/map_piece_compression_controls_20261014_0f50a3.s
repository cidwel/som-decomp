.setcpu "65816"
.segment "CODE"
.org $50A3
map_control_0f50a3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
