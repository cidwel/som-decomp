.setcpu "65816"
.segment "CODE"
.org $F010
map_control_0ff010:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
