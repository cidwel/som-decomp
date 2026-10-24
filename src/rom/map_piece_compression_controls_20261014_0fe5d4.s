.setcpu "65816"
.segment "CODE"
.org $E5D4
map_control_0fe5d4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
