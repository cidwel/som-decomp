.setcpu "65816"
.segment "CODE"
.org $980A
map_control_0f980a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
