.setcpu "65816"
.segment "CODE"
.org $4C0A
map_control_0c4c0a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
