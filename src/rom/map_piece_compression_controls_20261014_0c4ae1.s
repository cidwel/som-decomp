.setcpu "65816"
.segment "CODE"
.org $4AE1
map_control_0c4ae1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
