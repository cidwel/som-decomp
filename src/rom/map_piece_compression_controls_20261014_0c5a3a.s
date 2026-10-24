.setcpu "65816"
.segment "CODE"
.org $5A3A
map_control_0c5a3a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
