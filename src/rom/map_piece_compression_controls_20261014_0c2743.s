.setcpu "65816"
.segment "CODE"
.org $2743
map_control_0c2743:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
