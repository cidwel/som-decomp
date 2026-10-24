.setcpu "65816"
.segment "CODE"
.org $35DD
map_control_0e35dd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
