.setcpu "65816"
.segment "CODE"
.org $7169
map_control_0e7169:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
