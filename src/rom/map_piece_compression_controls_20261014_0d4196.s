.setcpu "65816"
.segment "CODE"
.org $4196
map_control_0d4196:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
