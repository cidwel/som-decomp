.setcpu "65816"
.segment "CODE"
.org $E243
map_control_0de243:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
