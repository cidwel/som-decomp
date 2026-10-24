.setcpu "65816"
.segment "CODE"
.org $5704
map_control_0d5704:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
