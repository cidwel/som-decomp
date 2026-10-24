.setcpu "65816"
.segment "CODE"
.org $8D00
map_control_0d8d00:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
