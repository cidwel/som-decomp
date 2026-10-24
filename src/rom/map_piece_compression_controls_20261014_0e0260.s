.setcpu "65816"
.segment "CODE"
.org $0260
map_control_0e0260:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
