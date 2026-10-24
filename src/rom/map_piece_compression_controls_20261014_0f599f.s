.setcpu "65816"
.segment "CODE"
.org $599F
map_control_0f599f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
