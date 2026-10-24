.setcpu "65816"
.segment "CODE"
.org $3760
map_control_0f3760:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
