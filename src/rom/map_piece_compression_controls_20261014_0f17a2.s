.setcpu "65816"
.segment "CODE"
.org $17A2
map_control_0f17a2:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E5 ; previous-row copy count
