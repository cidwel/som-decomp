.setcpu "65816"
.segment "CODE"
.org $7876
map_control_0f7876:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
