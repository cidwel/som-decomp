.setcpu "65816"
.segment "CODE"
.org $2A86
map_control_0f2a86:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
