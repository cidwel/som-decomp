.setcpu "65816"
.segment "CODE"
.org $6650
map_control_0e6650:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
