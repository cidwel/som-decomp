.setcpu "65816"
.segment "CODE"
.org $0B32
map_control_0e0b32:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
