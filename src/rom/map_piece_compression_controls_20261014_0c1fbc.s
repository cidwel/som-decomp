.setcpu "65816"
.segment "CODE"
.org $1FBC
map_control_0c1fbc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
