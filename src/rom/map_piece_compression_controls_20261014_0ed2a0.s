.setcpu "65816"
.segment "CODE"
.org $D2A0
map_control_0ed2a0:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
