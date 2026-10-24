.setcpu "65816"
.segment "CODE"
.org $B495
map_control_0db495:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
