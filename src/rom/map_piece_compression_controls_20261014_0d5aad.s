.setcpu "65816"
.segment "CODE"
.org $5AAD
map_control_0d5aad:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
