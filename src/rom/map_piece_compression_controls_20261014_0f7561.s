.setcpu "65816"
.segment "CODE"
.org $7561
map_control_0f7561:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
