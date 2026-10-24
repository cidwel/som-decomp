.setcpu "65816"
.segment "CODE"
.org $F785
map_control_0ef785:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
