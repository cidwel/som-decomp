.setcpu "65816"
.segment "CODE"
.org $01D0
map_control_0f01d0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
