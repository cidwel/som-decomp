.setcpu "65816"
.segment "CODE"
.org $6CFE
map_control_0f6cfe:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E1 ; previous-row copy count
