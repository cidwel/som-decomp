.setcpu "65816"
.segment "CODE"
.org $C8D2
map_control_0fc8d2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
