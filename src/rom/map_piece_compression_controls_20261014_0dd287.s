.setcpu "65816"
.segment "CODE"
.org $D287
map_control_0dd287:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
