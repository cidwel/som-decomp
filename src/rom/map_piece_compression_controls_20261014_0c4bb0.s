.setcpu "65816"
.segment "CODE"
.org $4BB0
map_control_0c4bb0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
