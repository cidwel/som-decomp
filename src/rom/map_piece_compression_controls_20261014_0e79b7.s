.setcpu "65816"
.segment "CODE"
.org $79B7
map_control_0e79b7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
