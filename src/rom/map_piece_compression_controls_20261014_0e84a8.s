.setcpu "65816"
.segment "CODE"
.org $84A8
map_control_0e84a8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
