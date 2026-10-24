.setcpu "65816"
.segment "CODE"
.org $7EFD
map_control_0c7efd:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
