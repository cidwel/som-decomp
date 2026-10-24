.setcpu "65816"
.segment "CODE"
.org $48B5
map_control_0c48b5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
