.setcpu "65816"
.segment "CODE"
.org $48E2
map_control_0c48e2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
