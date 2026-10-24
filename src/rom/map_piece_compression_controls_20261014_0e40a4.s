.setcpu "65816"
.segment "CODE"
.org $40A4
map_control_0e40a4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
