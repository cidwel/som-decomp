.setcpu "65816"
.segment "CODE"
.org $8D4B
map_control_0c8d4b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
