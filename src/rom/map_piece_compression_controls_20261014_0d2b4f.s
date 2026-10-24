.setcpu "65816"
.segment "CODE"
.org $2B4F
map_control_0d2b4f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
