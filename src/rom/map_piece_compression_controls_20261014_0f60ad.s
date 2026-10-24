.setcpu "65816"
.segment "CODE"
.org $60AD
map_control_0f60ad:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
