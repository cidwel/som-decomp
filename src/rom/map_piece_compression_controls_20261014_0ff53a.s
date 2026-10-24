.setcpu "65816"
.segment "CODE"
.org $F53A
map_control_0ff53a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
