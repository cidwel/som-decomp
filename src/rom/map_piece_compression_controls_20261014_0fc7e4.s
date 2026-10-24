.setcpu "65816"
.segment "CODE"
.org $C7E4
map_control_0fc7e4:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E4 ; previous-row copy count
