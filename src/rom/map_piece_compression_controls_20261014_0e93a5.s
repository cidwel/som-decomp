.setcpu "65816"
.segment "CODE"
.org $93A5
map_control_0e93a5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
