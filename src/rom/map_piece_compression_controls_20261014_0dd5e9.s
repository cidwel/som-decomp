.setcpu "65816"
.segment "CODE"
.org $D5E9
map_control_0dd5e9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
