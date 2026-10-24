.setcpu "65816"
.segment "CODE"
.org $0FDE
map_control_0f0fde:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E5 ; previous-row copy count
