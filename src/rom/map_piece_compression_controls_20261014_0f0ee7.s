.setcpu "65816"
.segment "CODE"
.org $0EE7
map_control_0f0ee7:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
