.setcpu "65816"
.segment "CODE"
.org $D562
map_control_0ed562:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
