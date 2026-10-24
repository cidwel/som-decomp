.setcpu "65816"
.segment "CODE"
.org $64C4
map_control_0f64c4:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
