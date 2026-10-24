.setcpu "65816"
.segment "CODE"
.org $4A11
map_control_0c4a11:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
