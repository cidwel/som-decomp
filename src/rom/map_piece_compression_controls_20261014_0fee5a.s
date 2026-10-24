.setcpu "65816"
.segment "CODE"
.org $EE5A
map_control_0fee5a:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
