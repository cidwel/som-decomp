.setcpu "65816"
.segment "CODE"
.org $E68D
map_control_0fe68d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
