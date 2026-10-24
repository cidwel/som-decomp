.setcpu "65816"
.segment "CODE"
.org $E4D7
map_control_0fe4d7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
