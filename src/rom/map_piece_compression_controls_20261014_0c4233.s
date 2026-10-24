.setcpu "65816"
.segment "CODE"
.org $4233
map_control_0c4233:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
