.setcpu "65816"
.segment "CODE"
.org $3619
map_control_0f3619:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
