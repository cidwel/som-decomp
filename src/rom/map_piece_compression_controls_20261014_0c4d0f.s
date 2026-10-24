.setcpu "65816"
.segment "CODE"
.org $4D0F
map_control_0c4d0f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
