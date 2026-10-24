.setcpu "65816"
.segment "CODE"
.org $E488
map_control_0fe488:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
