.setcpu "65816"
.segment "CODE"
.org $46F4
map_control_0c46f4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
