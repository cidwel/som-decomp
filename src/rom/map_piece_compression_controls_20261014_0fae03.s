.setcpu "65816"
.segment "CODE"
.org $AE03
map_control_0fae03:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
