.setcpu "65816"
.segment "CODE"
.org $D987
map_control_0ed987:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
