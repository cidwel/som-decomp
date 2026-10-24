.setcpu "65816"
.segment "CODE"
.org $493A
map_control_0c493a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
