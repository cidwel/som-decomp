.setcpu "65816"
.segment "CODE"
.org $B3E0
map_control_0fb3e0:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
