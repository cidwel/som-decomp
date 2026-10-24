.setcpu "65816"
.segment "CODE"
.org $ED18
map_control_0ded18:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
