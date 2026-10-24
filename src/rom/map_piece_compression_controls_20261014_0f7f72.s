.setcpu "65816"
.segment "CODE"
.org $7F72
map_control_0f7f72:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
