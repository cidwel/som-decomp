.setcpu "65816"
.segment "CODE"
.org $F1CA
map_control_0ff1ca:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
