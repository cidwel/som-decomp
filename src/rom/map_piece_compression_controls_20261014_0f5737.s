.setcpu "65816"
.segment "CODE"
.org $5737
map_control_0f5737:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
