.setcpu "65816"
.segment "CODE"
.org $49EA
map_control_0c49ea:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
