.setcpu "65816"
.segment "CODE"
.org $CCB2
map_control_0eccb2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
