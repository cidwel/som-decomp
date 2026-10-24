.setcpu "65816"
.segment "CODE"
.org $45F8
map_control_0e45f8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
