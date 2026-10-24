.setcpu "65816"
.segment "CODE"
.org $79E8
map_control_0f79e8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
