.setcpu "65816"
.segment "CODE"
.org $B4F1
map_control_0fb4f1:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
