.setcpu "65816"
.segment "CODE"
.org $2037
map_control_0f2037:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
