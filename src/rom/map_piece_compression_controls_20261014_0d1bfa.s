.setcpu "65816"
.segment "CODE"
.org $1BFA
map_control_0d1bfa:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count
