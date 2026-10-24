.setcpu "65816"
.segment "CODE"
.org $3DEE
map_control_0e3dee:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
