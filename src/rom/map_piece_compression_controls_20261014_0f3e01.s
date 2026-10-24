.setcpu "65816"
.segment "CODE"
.org $3E01
map_control_0f3e01:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
