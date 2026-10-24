.setcpu "65816"
.segment "CODE"
.org $E987
map_control_0ee987:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
