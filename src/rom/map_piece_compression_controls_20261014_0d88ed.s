.setcpu "65816"
.segment "CODE"
.org $88ED
map_control_0d88ed:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
