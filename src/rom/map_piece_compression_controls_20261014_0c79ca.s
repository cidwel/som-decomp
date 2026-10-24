.setcpu "65816"
.segment "CODE"
.org $79CA
map_control_0c79ca:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E3 ; previous-row copy count
