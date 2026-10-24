.setcpu "65816"
.segment "CODE"
.org $2F06
map_control_0d2f06:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
