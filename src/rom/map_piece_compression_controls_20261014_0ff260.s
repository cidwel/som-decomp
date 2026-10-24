.setcpu "65816"
.segment "CODE"
.org $F260
map_control_0ff260:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
