.setcpu "65816"
.segment "CODE"
.org $80A7
map_control_0c80a7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
