.setcpu "65816"
.segment "CODE"
.org $59AF
map_control_0e59af:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
