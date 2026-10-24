.setcpu "65816"
.segment "CODE"
.org $83CB
map_control_0e83cb:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
