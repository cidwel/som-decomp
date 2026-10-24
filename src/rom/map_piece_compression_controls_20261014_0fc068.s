.setcpu "65816"
.segment "CODE"
.org $C068
map_control_0fc068:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
