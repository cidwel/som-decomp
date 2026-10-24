.setcpu "65816"
.segment "CODE"
.org $BFBA
map_control_0fbfba:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
