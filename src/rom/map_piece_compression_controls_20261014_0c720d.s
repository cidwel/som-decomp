.setcpu "65816"
.segment "CODE"
.org $720D
map_control_0c720d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
