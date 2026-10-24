.setcpu "65816"
.segment "CODE"
.org $D31B
map_control_0ed31b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
