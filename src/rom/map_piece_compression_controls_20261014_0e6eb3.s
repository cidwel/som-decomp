.setcpu "65816"
.segment "CODE"
.org $6EB3
map_control_0e6eb3:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
