.setcpu "65816"
.segment "CODE"
.org $F8E9
map_control_0ef8e9:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
