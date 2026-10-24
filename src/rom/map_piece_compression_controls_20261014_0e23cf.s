.setcpu "65816"
.segment "CODE"
.org $23CF
map_control_0e23cf:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
