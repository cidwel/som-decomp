.setcpu "65816"
.segment "CODE"
.org $C783
map_control_0dc783:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
