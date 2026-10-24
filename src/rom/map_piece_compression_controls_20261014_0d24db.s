.setcpu "65816"
.segment "CODE"
.org $24DB
map_control_0d24db:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E2 ; previous-row copy count
