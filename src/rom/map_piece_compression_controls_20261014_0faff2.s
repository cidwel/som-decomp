.setcpu "65816"
.segment "CODE"
.org $AFF2
map_control_0faff2:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E7 ; previous-row copy count
