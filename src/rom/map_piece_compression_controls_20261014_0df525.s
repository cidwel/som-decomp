.setcpu "65816"
.segment "CODE"
.org $F525
map_control_0df525:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
