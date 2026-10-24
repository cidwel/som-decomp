.setcpu "65816"
.segment "CODE"
.org $01DA
map_control_0f01da:
    .byte $E9 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
