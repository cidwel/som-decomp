.setcpu "65816"
.segment "CODE"
.org $0D84
map_control_0d0d84:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
