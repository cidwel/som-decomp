.setcpu "65816"
.segment "CODE"
.org $EF88
map_control_0fef88:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
