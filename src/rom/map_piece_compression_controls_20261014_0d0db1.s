.setcpu "65816"
.segment "CODE"
.org $0DB1
map_control_0d0db1:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
