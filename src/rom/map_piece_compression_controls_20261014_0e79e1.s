.setcpu "65816"
.segment "CODE"
.org $79E1
map_control_0e79e1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
