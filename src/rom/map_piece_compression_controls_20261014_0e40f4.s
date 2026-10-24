.setcpu "65816"
.segment "CODE"
.org $40F4
map_control_0e40f4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
