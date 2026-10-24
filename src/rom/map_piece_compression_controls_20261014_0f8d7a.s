.setcpu "65816"
.segment "CODE"
.org $8D7A
map_control_0f8d7a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
