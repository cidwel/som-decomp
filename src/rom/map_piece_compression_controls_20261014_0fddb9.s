.setcpu "65816"
.segment "CODE"
.org $DDB9
map_control_0fddb9:
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
