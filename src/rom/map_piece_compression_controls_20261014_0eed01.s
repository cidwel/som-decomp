.setcpu "65816"
.segment "CODE"
.org $ED01
map_control_0eed01:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
