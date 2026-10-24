.setcpu "65816"
.segment "CODE"
.org $1FE2
map_control_0c1fe2:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
