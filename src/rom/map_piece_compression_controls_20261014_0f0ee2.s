.setcpu "65816"
.segment "CODE"
.org $0EE2
map_control_0f0ee2:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
