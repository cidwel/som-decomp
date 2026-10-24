.setcpu "65816"
.segment "CODE"
.org $37E3
map_control_0f37e3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
