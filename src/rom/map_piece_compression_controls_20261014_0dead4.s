.setcpu "65816"
.segment "CODE"
.org $EAD4
map_control_0dead4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
