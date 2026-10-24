.setcpu "65816"
.segment "CODE"
.org $195F
map_control_0e195f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
