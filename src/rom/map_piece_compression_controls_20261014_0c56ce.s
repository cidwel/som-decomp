.setcpu "65816"
.segment "CODE"
.org $56CE
map_control_0c56ce:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
