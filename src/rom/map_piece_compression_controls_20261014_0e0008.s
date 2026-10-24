.setcpu "65816"
.segment "CODE"
.org $0008
map_control_0e0008:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
