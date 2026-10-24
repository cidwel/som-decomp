.setcpu "65816"
.segment "CODE"
.org $72CE
map_control_0c72ce:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
