.setcpu "65816"
.segment "CODE"
.org $787A
map_control_0d787a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
