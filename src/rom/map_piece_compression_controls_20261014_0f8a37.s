.setcpu "65816"
.segment "CODE"
.org $8A37
map_control_0f8a37:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
