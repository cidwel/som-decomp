.setcpu "65816"
.segment "CODE"
.org $7440
map_control_0d7440:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
