.setcpu "65816"
.segment "CODE"
.org $80A1
map_control_0d80a1:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
