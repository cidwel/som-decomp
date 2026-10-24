.setcpu "65816"
.segment "CODE"
.org $982A
map_control_0f982a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
