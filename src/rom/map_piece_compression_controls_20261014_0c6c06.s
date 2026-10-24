.setcpu "65816"
.segment "CODE"
.org $6C06
map_control_0c6c06:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
