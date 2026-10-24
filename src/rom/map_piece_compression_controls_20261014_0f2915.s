.setcpu "65816"
.segment "CODE"
.org $2915
map_control_0f2915:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
