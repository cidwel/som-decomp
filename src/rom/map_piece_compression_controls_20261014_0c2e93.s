.setcpu "65816"
.segment "CODE"
.org $2E93
map_control_0c2e93:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
