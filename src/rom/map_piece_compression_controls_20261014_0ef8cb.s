.setcpu "65816"
.segment "CODE"
.org $F8CB
map_control_0ef8cb:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
