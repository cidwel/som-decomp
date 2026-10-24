.setcpu "65816"
.segment "CODE"
.org $3539
map_control_0e3539:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
