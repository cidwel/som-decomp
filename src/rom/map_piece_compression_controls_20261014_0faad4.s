.setcpu "65816"
.segment "CODE"
.org $AAD4
map_control_0faad4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
