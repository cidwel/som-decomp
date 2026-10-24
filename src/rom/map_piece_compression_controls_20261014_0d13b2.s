.setcpu "65816"
.segment "CODE"
.org $13B2
map_control_0d13b2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
