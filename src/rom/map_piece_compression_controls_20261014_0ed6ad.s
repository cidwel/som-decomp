.setcpu "65816"
.segment "CODE"
.org $D6AD
map_control_0ed6ad:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
