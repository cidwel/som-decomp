.setcpu "65816"
.segment "CODE"
.org $0E39
map_control_0e0e39:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
