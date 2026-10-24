.setcpu "65816"
.segment "CODE"
.org $DDE8
map_control_0edde8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
