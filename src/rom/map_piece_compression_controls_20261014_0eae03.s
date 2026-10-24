.setcpu "65816"
.segment "CODE"
.org $AE03
map_control_0eae03:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
