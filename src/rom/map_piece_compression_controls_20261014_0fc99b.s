.setcpu "65816"
.segment "CODE"
.org $C99B
map_control_0fc99b:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
