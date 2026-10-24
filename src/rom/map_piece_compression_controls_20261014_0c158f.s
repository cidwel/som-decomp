.setcpu "65816"
.segment "CODE"
.org $158F
map_control_0c158f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
