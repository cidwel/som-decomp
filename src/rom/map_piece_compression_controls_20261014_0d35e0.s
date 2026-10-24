.setcpu "65816"
.segment "CODE"
.org $35E0
map_control_0d35e0:
    .byte $E4 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
