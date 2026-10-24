.setcpu "65816"
.segment "CODE"
.org $6F02
map_control_0d6f02:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
