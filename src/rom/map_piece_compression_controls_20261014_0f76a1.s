.setcpu "65816"
.segment "CODE"
.org $76A1
map_control_0f76a1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
