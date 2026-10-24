.setcpu "65816"
.segment "CODE"
.org $25BC
map_control_0f25bc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
