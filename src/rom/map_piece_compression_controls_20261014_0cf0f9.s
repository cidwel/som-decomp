.setcpu "65816"
.segment "CODE"
.org $F0F9
map_control_0cf0f9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
