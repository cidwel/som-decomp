.setcpu "65816"
.segment "CODE"
.org $330D
map_control_0f330d:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E4 ; previous-row copy count
