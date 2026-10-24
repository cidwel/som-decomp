.setcpu "65816"
.segment "CODE"
.org $28C2
map_control_0e28c2:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
