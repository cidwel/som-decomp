.setcpu "65816"
.segment "CODE"
.org $282D
map_control_0e282d:
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
