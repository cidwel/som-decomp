.setcpu "65816"
.segment "CODE"
.org $C47D
map_control_0dc47d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
