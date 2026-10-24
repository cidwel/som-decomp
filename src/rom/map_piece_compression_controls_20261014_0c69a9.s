.setcpu "65816"
.segment "CODE"
.org $69A9
map_control_0c69a9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
