.setcpu "65816"
.segment "CODE"
.org $BC5B
map_control_0ebc5b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
