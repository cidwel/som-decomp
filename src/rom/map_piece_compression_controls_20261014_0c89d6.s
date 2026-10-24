.setcpu "65816"
.segment "CODE"
.org $89D6
map_control_0c89d6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
