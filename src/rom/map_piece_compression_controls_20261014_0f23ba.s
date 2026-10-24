.setcpu "65816"
.segment "CODE"
.org $23BA
map_control_0f23ba:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
