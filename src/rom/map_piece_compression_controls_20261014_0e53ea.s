.setcpu "65816"
.segment "CODE"
.org $53EA
map_control_0e53ea:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
